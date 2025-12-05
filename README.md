# Advent of Code 2025 in PonieScript
These are my solutions to Advent of Code 2025 in my language [PonieScript](https://github.com/HoneyPony/poniescript).

As of this writing, most of the language development is taking place on its
'misc' branch. So, if you want to run the code, you will need to use the
'misc' branch.

I do not yet have the build system set up perfectly well. The gist is that
you need to create a file in `$XDG_CONFIG_HOME/poniescript/build-config.toml`
that looks sort of like this:

```
# Path to the PonieScript repo
poni_src_path = "/home/me/poniescript"
# Path to the PonieScript command. Can just be 'poniescript' if it is in
# your $PATH
poniescript_path = "poniescript"

# Defaults for the toolchain list below
default_target = "local"
default_profile = "debug"

[toolchain.local.debug]
cc      = "clang -g"
linker  = "clang -fuse-ld=mold"
piped   = false
ways    = 1
```

Then, if the `ponies` command is in your path (this comes from the `poni-build-cli`
crate from the `poniescript` repo), you can run each solution such as:

```
$ cd day1
$ ponies run puzzle1
```

Note that essentially every puzzle requires the existance of a file called
"input.txt" besides it. These are the Advent of Code inputs, which as I understand
it are not meant to be redistributed.

There is also scaffolding for a Makefile to build the scripts, which is what
I was using before putting together the basic `ponies` build system during Advent
of Code. I have left the Makefile in place in case it is useful, although it may
be slightly misconfigured.
