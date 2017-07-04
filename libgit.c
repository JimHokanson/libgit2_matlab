#include "mex.h"
#include "repo.h"
#include "remote.h"
#include "commit.h"
#include "reference.h"
#include "git2.h"

//which install_name_tool

//install_name_tool -change /Users/jim/Documents/repos/matlab_git/libgit2_matlab/libgit2.dylib @executable_path/libgit2.dylib libgit.mexmaci64

//install_name_tool -id new_name old_name
//install_name_tool -id libgit2.dylib /Users/jim/Documents/repos/matlab_git/libgit2_matlab/libgit2.dylib

//https://libgit2.github.com/docs/guides/build-and-link/
//
//  They recommend linking statically with xcode

//  Follow links on this site to download
//  https://libgit2.github.com/

//  Mac Build Instructions
//  -----------------------
//  brew install cmake
//  mkdir build && cd build
//  cmake ..
//  cmake --build .
//  copied libgit2.dylib and git2.h and git2 folder

//  mex libgit2.dylib libgit.c

int locked = 0;

void shutdown() {
    git_libgit2_shutdown();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    
    //Use mexIsLocked
    if (!locked)
    {
        git_libgit2_init();
        mexAtExit(&shutdown);
        mexLock();
        locked = 1;
    }
    
    //libgit(type,sub_type,varargin)
    
    if (nrhs < 2){
        mexErrMsgIdAndTxt("libgit:init","At least two inputs are required");
    }else if (!mxIsClass(prhs[0],"double")){
        mexErrMsgIdAndTxt("libgit:init","First input must be a double");
    }else if (!mxIsClass(prhs[1],"double")){
        mexErrMsgIdAndTxt("libgit:init","Second input must be a double");
    }
    
    int type = (int) mxGetScalar(prhs[0]);
    
    //0 repo
    //1 remote
    //2 commit
    //3 reference
    
    switch (type) {
        case 0:
            //repository
            //repo(nlhs, plhs, nrhs, prhs);
            repo(MEX_INPUT);
            break;
        case 1:
            //remote
            remote(MEX_INPUT);
            break;
        case 2:
            commit(MEX_INPUT);
            break;
        case 3:
            reference(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_1","Input type not recognized");
    }
        
}