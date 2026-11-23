import argparse

def argumentparser(argv=None):
	argparser = argparse.ArgumentParser(prog="scorpion")
	argparser.add_argument("img_path", nargs="+", help="Path of the img to extract metadata.")
	args = argparser.parse_args(argv)
	return args
