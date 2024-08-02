# OS Slides

Jon Eyolfon's operating systems slides.

## Building

I have custom colors with pygmentize (you'll need to install).

    python3 -m venv venv
    source venv/bin/activate
    pip install -U pip
    pip install -e .

All slides should be buildable using `latexmk`, e.g.:

    cd 01-why-operating-systems
    latexmk -pvc
