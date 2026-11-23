# Arachnida

Two small command-line tools for the 42 cybersecurity module:

- **spider**: downloads images from a website, optionally following links recursively.
- **scorpion**: displays metadata (file info and EXIF data) of image files.

Supported image formats: `.jpg`, `.jpeg`, `.png`, `.gif`, `.bmp`

## Setup

Requires Python 3.10+.

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

The virtual environment must be active (`source venv/bin/activate`) whenever you run the programs.

## Usage

### spider

```bash
./spider [-r] [-l [N]] [-p PATH] URL
```

| Option | Description |
|---|---|
| `-r` | Recursively download images from linked pages on the same site |
| `-l [N]` | Maximum recursion depth (default: 5). Only used together with `-r` |
| `-p PATH` | Folder to save the images in (default: `./data/`) |

Examples:

```bash
./spider https://books.toscrape.com/
./spider -r -l 2 -p ./images https://books.toscrape.com/
```

### scorpion

```bash
./scorpion FILE [FILE ...]
```

Examples:

```bash
./scorpion photo.jpg
./scorpion data/*.jpg data/*.png
```
