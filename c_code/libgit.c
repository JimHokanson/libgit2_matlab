#include "mex.h"

//TODO: point to something that defines this 
#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include "branch.h"
#include "repo.h"
#include "remote.h"
#include "commit.h"
#include "oid.h"
#include "reference.h"
#include "status.h"


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
    
    //00 repo
    //01 remote
    //02 commit
    //03 reference
    //04 libgit
    //05 oid
    //
    //6 annotated
    //7 attr
    //8 blame
    //9 blob
    //10 branch
    //11 buf
    //12 checkout
    //13 cherrypick
    //14 clone
    //x commit
    //15 config
    //16 cred
    //17 describe
    //18 diff
    //19 fetch
    //20 filter
    //21 giterr
    //22 graph
    //23 hashsig
    //24 ignore
    //25 index
    //26 indexer
    //27 libgit2
    //28 mempack
    //29 merge
    //30 message
    //31 note
    //32 object
    //33 odb
    //34 oid
    //35 oidarray
    //36 openssl
    //37 packbuilder
    //38 patch
    //39 pathspec
    //40 proxy
    //41 push
    //42 rebase
    //43 refdb
    //44 reference
    //45 reflog
    //46 refspec
    //47 remote
    //48 repository
    //49 reset
    //50 revert
    //51 revparse
    //52 revwalk
    //53 signature
    //54 smart
    //55 stash
    //56 status
    //57 strarray
    //58 stream
    //59 submodule
    //60 tag
    //61 time
    //62 trace
    //63 transport
    //64 tree
    //65 treebuilder
    //66 worktree
    
    
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
        case 6:
            //annotead(MEX_INPUT);
            break;
        case 7:
            //attr(MEX_INPUT);
            break;
        case 8:
            //blame(MEX_INPUT);
            break;
        case 9:
            //blob(MEX_INPUT);
            break;
        case 10:
            branch(MEX_INPUT);
            break;
        case 11:
            //buf(MEX_INPUT);
            break;
        case 12:
            //checkout(MEX_INPUT);
            break;
        case 13:
            //cherrypick(MEX_INPUT);
            break;
        case 14:
            //clone(MEX_INPUT);
            break;
        case 15:
            //config(MEX_INPUT);
            break;
        case 16:
            //cred(MEX_INPUT);
            break;
        case 17:
            //describe(MEX_INPUT);
            break;
        case 18:
            //diff(MEX_INPUT);
            break;
        case 19:
            //fetch(MEX_INPUT);
            break;
        case 20:
            //filter(MEX_INPUT);
            break;
        case 21:
            //giterr(MEX_INPUT);
            break;
        case 22:
            //graph(MEX_INPUT);
            break;
        case 23:
            //hashsig(MEX_INPUT);
            break;
        case 24:
            //ignore(MEX_INPUT);
            break;
        case 25:
            //index(MEX_INPUT);
            break;
        case 26:
            //indexer(MEX_INPUT);
            break;
        case 27:
            //libgit2(MEX_INPUT);
            break;
        case 28:
            //mempack(MEX_INPUT);
            break;
        case 29:
            //merge(MEX_INPUT);
            break;
        case 30:
            //message(MEX_INPUT);
            break;
        case 31:
            //note(MEX_INPUT);
            break;
        case 32:
            //object(MEX_INPUT);
            break;
        case 33:
            //odb(MEX_INPUT);
            break;
        case 34:
            //oid(MEX_INPUT);
            break;
        case 35:
            //oidarray(MEX_INPUT);
            break;
        case 36:
            //openssl(MEX_INPUT);
            break;
        case 37:
            //packbuilder(MEX_INPUT);
            break;
        case 38:
            //patch(MEX_INPUT);
            break;
        case 39:
            //pathspec(MEX_INPUT);
            break;
        case 40:
            //proxy(MEX_INPUT);
            break;
        case 41:
            //push(MEX_INPUT);
            break;
        case 42:
            //rebase((MEX_INPUT);
            break;
        case 43:
            //refdb(MEX_INPUT);
            break;
        case 44:
            //reference(MEX_INPUT);
            break;
        case 45:
            //reflog(MEX_INPUT);
            break;
        case 46:
            //refspec(MEX_INPUT);
            break;
        case 47:
            //remote(MEX_INPUT);
            break;
        case 48:
            //repository(MEX_INPUT);
            break;
        case 49:
            //reset(MEX_INPUT);
            break;
        case 50:
            //revert(MEX_INPUT);
            break;
        case 51:
            //revparse(MEX_INPUT);
            break;
        case 52:
            //revwalk(MEX_INPUT);
            break;
        case 53:
            //signature(MEX_INPUT);
            break;
        case 54:
            //smart(MEX_INPUT);
            break;
        case 55:
            //stash(MEX_INPUT);
            break;
        case 56:
            status(MEX_INPUT);
            break;
        case 57:
            //strarray(MEX_INPUT);
            break;
        case 58:
            //stream(MEX_INPUT);
            break;
        case 59:
            //submodule(MEX_INPUT);
            break;
        case 60:
            //tag(MEX_INPUT);
            break;
        case 61:
            //time(MEX_INPUT);
            break;
        case 62:
            //trace(MEX_INPUT);
            break;
        case 63:
            //transport(MEX_INPUT);
            break;
        case 64:
            //tree(MEX_INPUT);
            break;
        case 65:
            //treebuilder(MEX_INPUT);
            break;
        case 66:
            //worktree(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_1","Input type not recognized");
    }
        
}