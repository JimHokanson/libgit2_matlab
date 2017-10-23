classdef branch < handle
    %
    %   Class:
    %   git.base.branch
    %
    %   See Also
    %   --------
    %   git.base.branch_iterator
    
    
    %   Design note
    %   -----------
    %   A branch is a reference. Rather than inheriting from reference I'm
    %   copying code. Ideally we would have the following:
    %
    %       ref_base
    %        /     \
    %     branch   ref_main 
    
    
    %Status: 
    
    
    %{
        repo = git.base.repository(file_path);
        ref_list = repo.getReferenceList;
        ref = repo.getReference(ref_list{1});
        b = ref.getAsBranch;
    %}
    
    properties (Hidden)
        h
    end
    
    properties (Dependent)
        is_remote
        is_head 
        branch_name
    end
    
    methods
        function value = get.is_remote(obj)
           value = libgit(3,17,obj.h); 
        end
        function value = get.is_head(obj)
           value = libgit(10,4,obj.h); 
        end
        function value = get.branch_name(obj)
           value = libgit(10,9,obj.h); 
        end
    end
    
    %Static methods
    %----------------------------------------------------------------------
    methods (Static)
        function value = getLocalBranchNames(repo)
            %
            %   value = git.base.branch.getLocalBranchNames()
            
            value = git.base.branch_iterator.getLocalBranchNames(repo);
        end
        function value = getRemoteBranchNames(repo)
            %
            %   value = git.base.branch.getRemoteBranchNames()

            value = git.base.branch_iterator.getRemoteBranchNames(repo);
        end
    end

	%Static constructor methods
    %----------------------------------------------------------------------
    methods (Static)
        function obj = fromReference(ref)
            %
            %   obj = git.base.branch.fromReference(ref)
            
            repo_h = ref.getRepoHandle();
            branch_name = libgit(10,9,ref.h);
            
            obj = git.base.branch.fromName(repo_h,branch_name,ref.is_remote);
        end
        function obj = fromName(repo,branch_name,is_remote)
            %
            %   obj = git.base.branch.fromName(repo_object,branch_name,is_remote)
            %
            %   obj = git.base.branch.fromName(repo_c_handle,branch_name,is_remote)
            
            %TODO: Why do we have to specify this? Can we have redundant
            %branches?????
            if is_remote
                branch_type = 1;
            else
                branch_type = 0;
            end
            
            if isobject(repo)
                repo_h = repo.h;
            else
                repo_h = repo;
            end
            
            %-3 : 
            h = libgit(10,7,repo_h,branch_name,branch_type);
            obj = git.base.branch(h);
        end
    end
    
    methods
        function obj = branch(h)
            %
            %   obj = git.base.branch(h);
            
            obj.h = h;
        end
        function delete(obj)
            libgit(3,13,obj.h);
        end
    end
end

% //01 git_branch_create
% //02 git_branch_create_from_annotated
% //03 git_branch_delete
% //04 git_branch_is_head
% //05 git_branch_iterator_free
% //06 git_branch_iterator_new
% X  07 git_branch_lookup
% //08 git_branch_move
% //09 git_branch_name
% //10 git_branch_next
% //11 git_branch_set_upstream
% //12 git_branch_upstream