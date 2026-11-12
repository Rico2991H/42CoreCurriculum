import requests
import ipaddress
import os
from html.parser import HTMLParser
from urllib.parse import urljoin, urlparse, urldefrag

#def	join_img_url(page_url, parser) :
#	for img in parser.images :
#		parser.abslinks.add(urljoin(page_url, img))

class MyHTMLParser(HTMLParser):
	def __init__(self, URL, home_page):
		super().__init__()
		#self.images = set()
		self.pagerefs = set()
		self.imglinks = set()
		self.page_url = URL
		self.allowed_domain = home_page

	def is_page(self, url):
		parsedurl = urlparse(url)
		if(parsedurl.scheme != 'https' and parsedurl.scheme != 'http'):
			return False
		if(parsedurl.hostname is None):
			return False
		if (parsedurl.hostname != self.allowed_domain):
			return False
		return True
		
	def handle_starttag(self, tag, attrs):
		#if (tag == 'a' or tag == 'img' or tag == 'div') :
		for name, value in attrs:
			if (name in ('href' ,'src', 'data-src')) :
				if value is None:
					continue
				joined_val = urljoin(self.page_url, value)
				cleaned_val,_ = urldefrag(joined_val)
				parsedurl = urlparse(cleaned_val)
				if (parsedurl.path == ''):
					parsedurl = parsedurl._replace(path="/")
				cleaned_val= parsedurl.geturl()
				to_check = parsedurl.path.lower()
				if to_check.endswith((".jpg", ".jpeg", ".png", ".gif", ".bmp")) :
					self.imglinks.add(cleaned_val)
					continue
				if (name =='href' and self.is_page(cleaned_val)) :
					self.pagerefs.add(cleaned_val)
					

def crawl_pages(parser, depth, max_depth, parsed_pages, found_images) :
	parsed_pages.add(parser.page_url)
	if depth != max_depth:
		for url in parser.pagerefs:
			if url in parsed_pages:
				continue
			parsed_pages.add(url)
			if not is_safe_url(url):
				print(f'URL: {url} unsafe, skipped')
				continue
			try: 
				with requests.get(url, stream=True, timeout=10) as response:	
					content_type = response.headers.get("Content-Type", "")
					if not is_safe_url(response.url) or not parser.is_page(response.url):
						print(f'URL: {response.url} unsafe or not allowed, skipped')
						continue
					if not content_type.startswith("text/html"):
						continue
					html_content = response.text
			except requests.exceptions.RequestException as e:
				print(f"Skipping {url}: {e}")
				continue
			new_parser = MyHTMLParser(response.url, parser.allowed_domain)
			new_parser.feed(html_content)
			found_images.update(new_parser.imglinks)
			crawl_pages(new_parser, depth + 1, max_depth, parsed_pages, found_images)
	return

def download_images(path, set_of_i) :
	os.makedirs(path, exist_ok=True)
	imagenumber = 1
	for i in set_of_i:
		_, ext = os.path.splitext(urlparse(i).path)
		filename = f"image{imagenumber}{ext}"
		try:
			if not is_safe_url(i):
				print('image URL unsafe skipped')
				continue
			response = requests.get(i, timeout=10)
			if not is_safe_url(response.url):
				print('URL unsafe skipped')
			if response.status_code == 200:
				fullpath = os.path.join(path, filename)
				with open(fullpath, "wb") as f:
					f.write(response.content)
		except Exception as e:
			print(f"Couldnt  download {i}: {e}")
		imagenumber += 1


def	is_safe_url(URL):
	parsedurl = urlparse(URL)
	if(parsedurl.scheme != 'https' and parsedurl.scheme != 'http'):
		return False
	if(parsedurl.password != None):
		return False
	if(parsedurl.username != None):
		return False
	if(parsedurl.hostname is None or parsedurl.hostname == 'localhost'):
		return False
	try:
		ipaddress.ip_address(parsedurl.hostname)
		return False
	except ValueError:
		pass
	return True
	
		

def	init_scraper(URL, max_depth, path) :
	if not is_safe_url(URL):
		print('URL unsafe program ends here')
		exit(1)
	try:
		response = requests.get(URL, timeout=10)
	except requests.exceptions.RequestException as e:
		print(f"{e}")
		exit(1)
	if not is_safe_url(response.url):
		print('URL unsafe skipped')
		exit(1)
	print('succesfull request on start URL')
	print(f"status code: {response.status_code}")
	html_content = response.text 
	parser = MyHTMLParser(response.url, urlparse(response.url).hostname)
	parsed_pages = set()
	found_images = set()
	parser.feed(html_content)
	found_images.update(parser.imglinks)
	print(f'starting recursive search max_depth = {max_depth}')
	crawl_pages(parser, 0, max_depth, parsed_pages, found_images)
	print(f'images retrieved download starting...')
	download_images(path, found_images)
	#print(parser.images)
	#print(found_images)
