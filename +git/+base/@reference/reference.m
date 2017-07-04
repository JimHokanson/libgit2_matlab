classdef reference < handle
    %
    %   Class:
    %   git.base.reference
    %
    %   https://libgit2.github.com/docs/guides/101-samples/#references
    
    properties (Hidden)
        h
    end
    
    properties
        repo
        ref_name
    end
%14 git_reference_has_log
%15 git_reference_is_branch
%16 git_reference_is_note
%17 git_reference_is_remote
%18 git_reference_is_tag
%19 git_reference_is_valid_name

%26 git_reference_name_to_id => oid (as object) - returns git_oid


%27 git_reference_next
%28 git_reference_next_name
%29 git_reference_normalize_name


%30 git_reference_owner - which repo

%31 git_reference_peel
%32 git_reference_remove
%33 git_reference_rename
%34 git_reference_resolve
%35 git_reference_set_target

%36 git_reference_shorthand - reference's short name

%37 git_reference_symbolic_create
%38 git_reference_symbolic_create_matching
%39 git_reference_symbolic_set_target
%40 git_reference_symbolic_target
%41 git_reference_target - returns git_oid pointed
%42 git_reference_target_peel
%43 git_reference_type
    properties (Dependent)
        
        
    end
    
    methods
        function obj = reference(repo,ref_name)
            %
            %   obj = git.base.reference(repo,ref_name)
            %
            %   Inputs
            %   -------
            %   ref_name : string
            %       e.g. HEAD, refs/heads/master, refs/tags/v0.1.0, 
            
            obj.h = libgit(3,24,repo.h,ref_name);
            obj.repo = repo;
            obj.ref_name = ref_name;
        end
    end
    methods
        function delete(obj)
            libgit(3,13,obj.h);
        end
    end
    
end

%https://libgit2.github.com/libgit2/#HEAD/group/reference
%
%
%01 git_reference__alloc
%02 git_reference__alloc_symbolic
%03 git_reference_cmp
%04 git_reference_create
%05 git_reference_create_matching
%06 git_reference_delete
%07 git_reference_dup
%08 git_reference_dwim
%09 git_reference_ensure_log
%10 git_reference_foreach
%11 git_reference_foreach_glob
%12 git_reference_foreach_name
%13 git_reference_free
%14 git_reference_has_log
%15 git_reference_is_branch
%16 git_reference_is_note
%17 git_reference_is_remote
%18 git_reference_is_tag
%19 git_reference_is_valid_name
%20 git_reference_iterator_free
%21 git_reference_iterator_glob_new
%22 git_reference_iterator_new
%23 git_reference_list
%x 24 git_reference_lookup
%25 git_reference_name
%26 git_reference_name_to_id
%27 git_reference_next
%28 git_reference_next_name
%29 git_reference_normalize_name
%30 git_reference_owner
%31 git_reference_peel
%32 git_reference_remove
%33 git_reference_rename
%34 git_reference_resolve
%35 git_reference_set_target
%36 git_reference_shorthand
%37 git_reference_symbolic_create
%38 git_reference_symbolic_create_matching
%39 git_reference_symbolic_set_target
%40 git_reference_symbolic_target
%41 git_reference_target - Get the OID pointed to by a direct reference
%42 git_reference_target_peel
%43 git_reference_type

