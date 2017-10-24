classdef commit < handle
    %
    %   Class:
    %   git.base.commit
    %
    %   Still in progress, not working ...
    
    properties (Hidden)
        h
    end
    
    properties (Dependent)
        encoding
        message
        summary
        body
        time
        offset_in_min
        
        committer %git.base.signature
        %person that last applied the patch
        
        author %git.base.signature
        %original author
        
        header
        tree_id
    end
    
    methods
        function value = get.encoding(obj)
            value = libgit(2,19,obj.h);
            if isempty(value)
                value = 'UTF8';
            end
        end
        function value = get.message(obj)
            value = libgit(2,18,obj.h);
        end
        function value = get.summary(obj)
            value = libgit(2,27,obj.h);
        end
        function value = get.body(obj)
            value = libgit(2,3,obj.h);
        end
        function value = get.time(obj)
            value = [];
        end
        function value = get.offset_in_min(obj)
            value = [];
        end
        function value = get.committer(obj)
            temp = libgit(2,4,obj.h);
            value = git.base.signature(temp);
        end
        function value = get.author(obj)
            temp = libgit(2,2,obj.h);
            value = git.base.signature(temp);
        end
        function value = get.tree_id(obj)
            value = libgit(2,31,obj.h);
        end
    end
    
    methods (Static)
        function commit = fromRepoAndID(repo,oid)
            h = libgit(2,16,repo.h,oid.h);
            commit = git.base.commit(h);
        end
    end
    
    methods
        function obj = commit(commit_h)
            %
            %   obj = git.base.commit(ref)  TODO
            %
            %   obj = git.base.commit(repo,oid)
            
            obj.h = commit_h;
        end
        function tree = getTree(obj)
            tree_h = libgit(2,30,obj.h);
            tree = git.base.tree(tree_h);
        end
        function oid = getOID(obj)
            oid_raw = libgit(2,15,obj.h);
            oid = git.base.oid(oid_raw);
        end
        function getParent(obj)
            
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