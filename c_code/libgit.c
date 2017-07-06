#include "mex.h"
#include "repo.h"
#include "remote.h"
#include "commit.h"
#include "reference.h"

//TODO: point to something that defines this 
#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif


//which install_name_tool

//install_name_tool -change /Users/jim/Documents/repos/matlab_git/libgit2_matlab/libgit2.dylib @executable_path/libgit2.dylib libgit.mexmaci64

//install_name_tool -id new_name old_name
//install_name_tool -id libgit2.dylib /Users/jim/Documents/repos/matlab_git/libgit2_matlab/libgit2.dylib

//https://libgit2.github.com/docs/guides/build-and-link/
//
//  They recommend linking statically with xcode

//  Follow links on this site to download
//  https://libgit2.github.com/

//
//  https://github.com/libgit2/libgit2/archive/v0.26.0.zip
//
//  Windows
//  -------------
//  - used cmake gui
//  - opened generated solution in visual studio
//  - compiled with visual studio
//  - copied git2.lib and headers into folders
//  - copy git2.dll over as well

//  Mac Build Instructions
//  -----------------------
//  brew install cmake
//  mkdir build && cd build
//  cmake ..
//  cmake --build .
//  copied libgit2.dylib and git2.h and git2 folder

// Windows
// -------
// mex git2.lib libgit.c
//
// Mac OS
// ------
// mex libgit2.dylib libgit.c

int locked = 0;

void shutdown() {
    git_libgit2_shutdown();
}

void get_libgit_features(MEX_DEF_INPUT){
    int features = git_libgit2_features();
    plhs[0] = mxCreateLogicalMatrix(1,3);
    bool *data = (bool *)mxGetData(plhs[0]);
    *data = (features & GIT_FEATURE_THREADS) > 0;
    *(data+1) = (features & GIT_FEATURE_HTTPS) > 0;
    *(data+2) = (features & GIT_FEATURE_SSH) > 0;
    //GIT_FEATURE_THREADS 
    //GIT_FEATURE_HTTPS 
    //GIT_FEATURE_SSH 
}

void get_libgit_option(MEX_DEF_INPUT){
   //https://libgit2.github.com/libgit2/#HEAD/group/libgit2/git_libgit2_opts
    
    //01  GIT_OPT_GET_MWINDOW_SIZE
    //02  GIT_OPT_GET_MWINDOW_MAPPED_LIMIT
    //03  GIT_OPT_GET_SEARCH_PATH
    //04  GIT_OPT_GET_CACHED_MEMORY
    //05  GIT_OPT_GET_TEMPLATE_PATH
    int option = (int)mxGetScalar(prhs[2]);
    switch (option){
        case 1:
            //opts(GIT_OPT_GET_MWINDOW_SIZE, size_t *):
            //> Get the maximum mmap window size
            break;
        case 2:
            //opts(GIT_OPT_GET_MWINDOW_MAPPED_LIMIT, size_t *):
            //> Get the maximum memory that will be mapped in 
            //total by the library
            break;
        case 3:
            //opts(GIT_OPT_GET_SEARCH_PATH, int level, git_buf *buf)
            //> Get the search path for a given level of config data.  
            //"level" must be one of 
            //      `GIT_CONFIG_LEVEL_SYSTEM`, 
            //      `GIT_CONFIG_LEVEL_GLOBAL`,       
            //      `GIT_CONFIG_LEVEL_XDG`, or 
            //      `GIT_CONFIG_LEVEL_PROGRAMDATA`.   
            //  
            //> The search path is written to the `out` buffer.
            break;
        case 4:
            //opts(GIT_OPT_GET_CACHED_MEMORY, ssize_t *current, ssize_t *allowed)
            //> Get the current bytes in cache and the maximum that would be      
            //  allowed in the cache.
            break;
        case 5:
            //opts(GIT_OPT_GET_TEMPLATE_PATH, git_buf *out)
            //> Get the default template path.       
            //> The path is written to the `out` buffer.
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_3","libgit.h, option not recognized");
    }
}

void set_libgit_option(MEX_DEF_INPUT){
   //https://libgit2.github.com/libgit2/#HEAD/group/libgit2/git_libgit2_opts 
    
    //01  GIT_OPT_GET_MWINDOW_SIZE
    //02  GIT_OPT_GET_MWINDOW_MAPPED_LIMIT
    //03  GIT_OPT_GET_SEARCH_PATH
    //04  GIT_OPT_SET_CACHE_OBJECT_LIMIT
    //05  GIT_OPT_SET_CACHE_MAX_SIZE
    //06  GIT_OPT_ENABLE_CACHING
    //07  GIT_OPT_SET_TEMPLATE_PATH
    //08  GIT_OPT_SET_SSL_CERT_LOCATIONS
    //09  GIT_OPT_SET_USER_AGENT
    //10  GIT_OPT_ENABLE_STRICT_OBJECT_CREATION
    //11  GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION
    //12  GIT_OPT_SET_SSL_CIPHERS
    
    int option = (int)mxGetScalar(prhs[2]);
    switch (option){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_3","libgit.h, option not recognized");
    }
}

void get_libgit_version(MEX_DEF_INPUT){
    int major;
    int minor;
    int rev;
    //void git_libgit2_version(int *major, int *minor, int *rev);
    git_libgit2_version(&major, &minor, &rev);
    plhs[0] = mxCreateNumericMatrix(1,3,mxINT32_CLASS,0);
    int *data = (int *)mxGetData(plhs[0]);
    *data = major;
    *(data+1) = minor;
    *(data+2) = rev;
    
}

void libgit(MEX_DEF_INPUT){
    
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 0:
            //features
            get_libgit_features(MEX_INPUT);
            break;
        case 1:
            //options
            get_libgit_option(MEX_INPUT);
            break;
        case 2:
            set_libgit_option(MEX_INPUT);
            break;
        case 3:
            //version
            get_libgit_version(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","libgit.h, input sub-type not recognized");
    }
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
    //4 libgit
    //5 oid
    
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
        case 4:
            libgit(MEX_INPUT);
            break;
        case 5:
            oid(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_1","Input type not recognized");
    }
        
}