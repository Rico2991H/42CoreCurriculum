import argparse

def argumentparser(argv=None):
	argparser = argparse.ArgumentParser(prog="spider")
	argparser.add_argument("-r", action="store_true", help="recursively downloads the images in the given URL.")
	argparser.add_argument("-l", nargs="?", default=None, metavar="N", help="maximum depth level of the recursive download (default: 5).")
	argparser.add_argument("-p", default="./data/", help="location for downloaded files (default: ./data/).")
	argparser.add_argument("url", nargs="?", help="URL of the page to scrape.")
	args = argparser.parse_args(argv)

	# -l given without a number, and it swallowed the URL: give it back
	if args.url is None and args.l is not None and not args.l.isdigit():
		args.url = args.l
		args.l = None

	if args.url is None:
		argparser.error("the following arguments are required: url")

	# convert -l ourselves, since it arrives as a string
	if args.l is None:
		args.l = 5
	elif args.l.isdigit():
		args.l = int(args.l)
	else:
		argparser.error(f"argument -l: invalid depth: '{args.l}'")

	return args