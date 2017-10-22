#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"


void oid_cmp(MEX_DEF_INPUT){
    //1 - Compare two oid structures.
    //
    //int git_oid_cmp(const git_oid *a, const git_oid *b);
    
}

void oid_cpy(MEX_DEF_INPUT){
    //2 - Copy an oid from one structure to another.
    //
    //void git_oid_cpy(git_oid *out, const git_oid *src);
}

void oid_equal(MEX_DEF_INPUT){
    //3 - Compare two oid structures for equality
    //
    //int git_oid_equal(const git_oid *a, const git_oid *b);


}

void oid_fmt(MEX_DEF_INPUT){
    //4 - Format a git_oid into a hex string.
    //
    //void git_oid_fmt(char *out, const git_oid *id);

}

void oid_fromraw(MEX_DEF_INPUT){
    //5 - Copy an already raw oid into a git_oid structure.
    //
    //  void git_oid_fromraw(git_oid *out, const unsigned char *raw);
}

void oid_fromstr(MEX_DEF_INPUT){
    //6 - Parse a hex formatted object id into a git_oid.
    //
    //int git_oid_fromstr(git_oid *out, const char *str);
}

void oid_fromstrn(MEX_DEF_INPUT){
    //7 - Parse N characters of a hex formatted object id into a git_oid.
    //
    //int git_oid_fromstrn(git_oid *out, const char *str, size_t length);

}

void oid_fromstrp(MEX_DEF_INPUT){
    //8 - Parse a hex formatted null-terminated string into a git_oid.
    //
    //int git_oid_fromstrp(git_oid *out, const char *str);


}

void oid_iszero(MEX_DEF_INPUT){
    //9 = Check is an oid is all zeros.
    //
    //int git_oid_iszero(const git_oid *id);


}

void oid_ncmp(MEX_DEF_INPUT){
    //10 - Compare the first 'len' hexadecimal characters (packets of 4 bits) of two oid structures.
    //
    //int git_oid_ncmp(const git_oid *a, const git_oid *b, size_t len);


}

void oid_nfmt(MEX_DEF_INPUT){
    //11 - Format a git_oid into a partial hex string.
    //
    //void git_oid_nfmt(char *out, size_t n, const git_oid *id);

}

void oid_pathfmt(MEX_DEF_INPUT){
    //12 - Format a git_oid into a loose-object path string.
    //
    //void git_oid_pathfmt(char *out, const git_oid *id);


}

void oid_shorten_add(MEX_DEF_INPUT){
    //13 - Add a new OID to set of shortened OIDs and calculate the minimal length to uniquely identify all the OIDs in the set.
    //
    //int git_oid_shorten_add(git_oid_shorten *os, const char *text_id);

}

void oid_shorten_free(MEX_DEF_INPUT){
    //14 - Free an OID shortener instance
    //
    //void git_oid_shorten_free(git_oid_shorten *os);


}

void oid_shorten_new(MEX_DEF_INPUT){
    //15 - Create a new OID shortener.
    //
    //git_oid_shorten * git_oid_shorten_new(size_t min_length);


    
}

void oid_strcmp(MEX_DEF_INPUT){
    //16 - Compare an oid to an hex formatted object id.
    //
    //int git_oid_strcmp(const git_oid *id, const char *str);


}

void oid_streq(MEX_DEF_INPUT){
    //17 - Check if an oid equals an hex formatted object id.
    //
    //int git_oid_streq(const git_oid *id, const char *str);


}

void oid_tostr(MEX_DEF_INPUT){
    //18 - Format a git_oid into a buffer as a hex format c-string.
    //
    //char * git_oid_tostr(char *out, size_t n, const git_oid *id);


}

void oid_tostr_s(MEX_DEF_INPUT){
    //19 - Format a git_oid into a statically allocated c-string.
    //
    //char * git_oid_tostr_s(const git_oid *oid);

}

void oid(MEX_DEF_INPUT)
{

    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 1:
            oid_cmp(MEX_INPUT);
            break;
        case 2:
            oid_cpy(MEX_INPUT);
            break;
        case 3:
            oid_equal(MEX_INPUT);
            break;
        case 4:
            oid_fmt(MEX_INPUT);
            break;
        case 5:
            oid_fromraw(MEX_INPUT);
            break;
        case 6:
            oid_fromstr(MEX_INPUT);
            break;
        case 7:
            oid_fromstrn(MEX_INPUT);
            break;
        case 8:
            oid_fromstrp(MEX_INPUT);
            break;
        case 9:
            oid_iszero(MEX_INPUT);
            break;
        case 10:
            oid_ncmp(MEX_INPUT);
            break;
        case 11:
            oid_nfmt(MEX_INPUT);
            break;
        case 12:
            oid_pathfmt(MEX_INPUT);
            break;
        case 13:
            oid_shorten_add(MEX_INPUT);
            break;
        case 14:
            oid_shorten_free(MEX_INPUT);
            break;
        case 15:
            oid_shorten_new(MEX_INPUT);
            break;
        case 16:
            oid_strcmp(MEX_INPUT);
            break;
        case 17:
            oid_streq(MEX_INPUT);
            break;
        case 18:
            oid_tostr(MEX_INPUT);
            break;
        case 19:
            oid_tostr_s(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","oid.h, input sub-type not recognized");
            
    }
}

//1 git_oid_cmp
//2 git_oid_cpy
//3 git_oid_equal
//4 git_oid_fmt
//5 git_oid_fromraw
//6 git_oid_fromstr
//7 git_oid_fromstrn
//8 git_oid_fromstrp
//9 git_oid_iszero
//10 git_oid_ncmp
//11 git_oid_nfmt
//12 git_oid_pathfmt
//13 git_oid_shorten_add
//14 git_oid_shorten_free
//15 git_oid_shorten_new
//16 git_oid_strcmp
//17 git_oid_streq
//18 git_oid_tostr
//19 git_oid_tostr_s







