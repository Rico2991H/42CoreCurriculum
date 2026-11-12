from . import md_extractor, cli

def main():
	print('starting program')
	args = cli.argumentparser()
	md_extractor.display_data(args.img_path)

main()