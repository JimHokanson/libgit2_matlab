#include "mex.h"
#include "git2.h"

//https://libgit2.github.com/docs/guides/build-and-link/
//
//  They recommend linking statically with xcode

//  Mac Build Instructions
//  -----------------------
//  brew install cmake
//  mkdir build && cd build
//  cmake ..
//  cmake --build .
//  copied libgit2.dylib and git2.h and git2 folder

//  mex libgit2.dylib libgit.c

//https://libgit2.github.com/docs/guides/101-samples/

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    
    git_libgit2_init();
    
    git_repository *repo = NULL;
    int error = git_repository_open(&repo, "/Users/jim/Documents/repos/matlab_git/libgit2_matlab/");
    
    mexPrintf("Error %d\n",error);
    
    git_remote *remote = NULL;
    error = git_remote_lookup(&remote, repo, "origin");
    
    const char *url  = git_remote_url(remote);
    
    mexPrintf("url: %s\n",url);
    
    //free(url)
    
    //This needs to be freed by the user
    //How do we know how many we have????
    //
    //Need to find a usage example ...
    //git_strarray remotes = {0};
    //int error = git_remote_list(&remotes, repo);
    
    git_libgit2_shutdown();
    
}