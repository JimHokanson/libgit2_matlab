#include "mex.h"

//I don't know that we will ever use this 

//https://libgit2.github.com/libgit2/#HEAD/group/graph

void graph_ahead_behind(MEX_DEF_INPUT){
    //1 - Count the number of unique commits between two commit objects
    //
    //  int git_graph_ahead_behind(size_t *ahead, size_t *behind,
    //          git_repository *repo, const git_oid *local, 
    //          const git_oid *upstream);
    
    

}

void graph_descendant_of(MEX_DEF_INPUT){
    //2 - Determine if a commit is the descendant of another commit.
    //
    //  int git_graph_descendant_of(git_repository *repo, 
    //          const git_oid *commit, const git_oid *ancestor);

}

void graph(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            graph_ahead_behind(MEX_INPUT);
            break;
        case 2:
            graph_descendant_of(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:graph","graph.h, input sub-type not recognized");
    }
}

//1 git_graph_ahead_behind
//2 git_graph_descendant_of