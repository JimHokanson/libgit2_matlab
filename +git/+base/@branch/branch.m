classdef branch < git.base.reference
    %
    %   Class:
    %   git.base.branch
    
    properties
        h
    end
    
    properties
        is_remote
    end
    
    methods (Static)
        function value = getLocalBranchNames()
            %
            %   value = git.base.branch.getLocalBranchNames()
            
            value = [];
        end
        function value = getRemoteBranchNames()
            %
            %   value = git.base.branch.getRemoteBranchNames()

            value = [];
        end
        function obj = fromName(repo,branch_name,is_remote)
            %
            %   obj = git.base.branch.fromName(repo,branch_name,is_remote)
            
            if is_remote
                branch_type = 1;
            else
                branch_type = 0;
            end
            h = libgit2(10,7,repo.h,branch_name,branch_type);
            obj = git.base.branch(h);
        end
    end
    
    methods
        function obj = branch(h)
            obj.h = h;
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