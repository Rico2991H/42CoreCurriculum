import argparse

def argumentparser(argv=None):
	argparser = argparse.ArgumentParser(prog="ft_otp")
	argparser.add_argument("-g", help="Input a Hex key of at least 64 characters")
	argparser.add_argument("-k", help="Generates a new temporary password when key is given as an arg")
	args = argparser.parse_args(argv)

	return args