classdef commit < handle
    %
    %   Class:
    %   git.base.commit
    %
    %   Still in progress, not working ...
    
    properties (Hidden)
        h
    end
    
    properties
        repo
        commit_name
    end
    
    methods
        function obj = commit(repo,commit_name)
            
            obj.h = libgit(2,22,repo.h,commit_name);
            obj.repo = repo;
            obj.commit_name = commit_name; 
        end
    end
    methods
        function delete(obj)
            libgit(2,13,obj.h);
        end
    end
    
end

%01 git_commit_amend
%02 git_commit_author
%03 git_commit_body
%04 git_commit_committer
%05 git_commit_create
%06 git_commit_create_buffer
%07 git_commit_create_from_callback
%08 git_commit_create_from_ids
%09 git_commit_create_v
%10 git_commit_create_with_signature
%11 git_commit_dup
%12 git_commit_extract_signature
%x 13 git_commit_free
%14 git_commit_header_field
%15 git_commit_id
%x 16 git_commit_lookup
%17 git_commit_lookup_prefix
%18 git_commit_message
%19 git_commit_message_encoding
%20 git_commit_message_raw
%21 git_commit_nth_gen_ancestor
%22 git_commit_owner
%23 git_commit_parent
%24 git_commit_parent_id
%25 git_commit_parentcount
%26 git_commit_raw_header
%27 git_commit_summary
%28 git_commit_time
%29 git_commit_time_offset
%30 git_commit_tree
%31 git_commit_tree_id