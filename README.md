# libgit2_matlab

libgit2_matlab is a Matlab interface to the libgit2 library. It is in the very very early stages of development.

My immediate goal is to facilitate reporting of the status of a local repository relative to a remote, and to allow automatic updating of the local copy based on the remote.

#Status

The extent of my implemented code is as follows. It doesn't accomplish much right now. Note that I've only compiled the code for Mac OS so far.

```
file_path = '/path/to/repo';
repo = git.base.repository(file_path);
remote = repo.lookupRemote('origin');
list = git.base.remote.getList(repo)
```

# Options for interfacing Matlab with git

Options for interfacing with git:
1. The Git Shell
2. JGit
3. Libgit2
4. Libgit2 wrappers like pygit2
5. others? - probably, but I think these are the main ones

See also: https://git-scm.com/book/en/v2/Appendix-B%3A-Embedding-Git-in-your-Applications-Command-line-Git

## Git shell

https://git-scm.com/

The git shell is the reference implementation for git. Unfortunately, the interface is via the command line. Inputs to the shell are meant to be done interactively, and outputs are meant to be read by a human. Although it is possible to interface with git via the shell, any programmatic understanding of the output would require parsing of free-form text and hoping that nothing changes.

## JGit

https://eclipse.org/jgit/

To get around not having a programmatic interface to git, JGit was developed for Java code. At first this was my preferred option, but I'm not as comfortable with Java as C, and Java always seems to have so many classes. The one thing that really frustrated me is Matlab's integration of Java. More specifically, Matlab ships with a specific version of Java, which can be out of date. For example, as of 2017A Matlab ships with Java 7, even though Java 8 has been out for 3 years. Even though an update to Java 8 is likely going to be released soon, I didn't want to force users to link Matlab with a different Java version.

## Libgit2 and wrappers

https://libgit2.github.com/

The other option is using Libgit2. Libgit2 is a C implementation of git. Although working with this library requires careful management of memory, it has been straightforward so far to use. There are numerous wrappers for libgit2. Of particular interest is something like pygit2, a Python wrapper for libgit2. Matlab can interface with Python, but this requires installing and managing Python. There may be other options, but interfacing with C is relatively easy from Matlab, so we'll see where this project goes ...
