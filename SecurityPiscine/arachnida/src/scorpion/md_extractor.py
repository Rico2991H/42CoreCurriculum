from PIL import Image
from PIL import ExifTags
from datetime import datetime
import os


def data_looper(exif_input, title, name_table):
	print(title)
	for tag, value in exif_input.items():
		name = name_table.get(tag, tag)
		if (name in ('ExifOffset', 'GPSInfo')):
			continue
		if isinstance(value, bytes):
			text = value.decode(errors="replace")
			if text.isprintable():
				value = text
			else:
				value = value.hex()
		print(f"{name}: {value}")



def	display_data(path):
	stats = os.stat(path)
	with Image.open(path) as img:
		exif_data = img.getexif()
		megapixels = (img.size[0] * img.size[1]/1000000)
		print()
		print("--Image data--")
		print(f"Filename: {img.filename}")
		print(f"Format: {img.format}")
		print(f"Mode: {img.mode}")
		print(f"Palette: {img.palette}")
		print(f"Width: {img.width}")
		print(f"Height: {img.height}")
		print(f"Megapixels: {round(megapixels, 2)}")
		print()
		print("--OS data--")
		print(f"Size: {round(stats.st_size / 1024)} KB")
		created = getattr(stats, "st_birthtime", None)
		if created is not None:
			print(f"Created: {datetime.fromtimestamp(created)}")
		else:
			print("Created: Not available on this system.")
		print(f"Last modified: {datetime.fromtimestamp(stats.st_mtime)}")
		print()
		if exif_data:
			data_looper(exif_data, "--EXIF--", ExifTags.TAGS)
			E_data = exif_data.get_ifd(ExifTags.IFD.Exif)
			data_looper(E_data, "--EXIF details--", ExifTags.TAGS)
			gps_data = exif_data.get_ifd(ExifTags.IFD.GPSInfo)
			data_looper(gps_data, "--GPS info--",ExifTags.GPSTAGS)
		else:
			print("no EXIF data found")