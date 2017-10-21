classdef reference < handle
    %
    %   Class:
    %   git.base.reference
    %
    %   https://libgit2.github.com/docs/guides/101-samples/#references
    
    %{
    repo = git.base.repository(file_path);
    ref_list = repo.getReferenceList;
    ref = git.base.reference.fromRepoAndName(repo,ref_list{3});
    %}
    
    properties (Hidden)
        h
    end
    
    properties

    end
    
    properties (Dependent)
        repo
        name
        has_log
        is_branch
        is_note
        is_remote
        is_tag
        shorthand
        type
        oid
    end
    
    methods
        function value = get.repo(obj)
            value = libgit(3,30,obj.h);
        end
        function value = get.name(obj)
            value = libgit(3,25,obj.h);
        end
        function value = get.has_log(obj)
            value = [];
        end
        function value = get.is_branch(obj)
            value = libgit(3,15,obj.h);
        end
        function value = get.is_note(obj)
            value = [];
        end
        function value = get.is_remote(obj)
            value = libgit(3,17,obj.h);
        end
        function value = get.is_tag(obj)
            value = libgit(3,18,obj.h); 
        end
        function value = get.shorthand(obj)
            value = libgit(3,36,obj.h);
        end
        function value = get.oid(obj)
            
            oid_raw = libgit(3,41,obj.h);
            value = git.base.oid(oid_raw);
           
        end
    end
    
    

    methods
%         function value = get.oid(obj)
%             temp = libgit(3,26,obj.repo.h,obj.ref_name);
%             %This may change
%             value = git.base.oid(temp);
%         end
%         function value = get.owner(obj)
%             value = obj.repo;
%         end
    end
    
    
    methods (Static)
%         function isValidReferenceName(ref_name)
%             
%         end
    end
    
    %Constructors
    %-------------------------------------------------------------------
    methods (Static)
        function ref = fromRepoAndName(repo,ref_name)
            %
            %   ref = git.base.reference.fromRepoAndName(repo,ref_name)
            
            h = libgit(3,24,repo.h,ref_name);
            ref = git.base.reference(h);
        end
    end
    
    methods
        function obj = reference(h)
            %
            %   obj = git.base.reference(h)
            %
            %   Inputs
            %   -------
            %   ref_name : string
            %       e.g. HEAD, refs/heads/master, refs/tags/v0.1.0, 
            
            if isempty(h) || h == 0
                error('Ibvalid reference handle')
            end
            obj.h = h;
        end
    end
    methods
        function delete(obj)
            libgit(3,13,obj.h);
        end
    end
    %-------------------------------------------------------------------
    
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

%x 14 git_reference_has_log
%x 15 git_reference_is_branch
%x 16 git_reference_is_note
%x 17 git_reference_is_remote
%x 18 git_reference_is_tag
%x 19 git_reference_is_valid_name
%x 20 git_reference_iterator_free
%x 21 git_reference_iterator_glob_new
%22 git_reference_iterator_new
%23 git_reference_list
%x 24 git_reference_lookup
%25 git_reference_name
%x 26 git_reference_name_to_id
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

