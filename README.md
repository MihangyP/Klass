## Klass
This is a simple cpp class generator writen in cpp. It create two files : `<ClassName>.hpp` and `<ClassName>.cpp`. I design it to myself but it completely open source, fork it and adapt to your own needs.

### Quick Start
```console
$ make
$ ./Klass <ClassName>
```
Or you can copy the generated program in your `~/.local/bin`, export the new PATH and call the program everywhere.
```console
$ make
$ cp Klass ~/.local/bin
$ echo "PATH=\"$HOME/.local/bin:$PATH\"" > .bashrc
$ source ~/.bashrc
$ Klass <ClassName>
```
