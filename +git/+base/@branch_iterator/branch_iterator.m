classdef branch_iterator
    %
    %   Class:
    %   git.base.branch_iterator
    
    properties
        h
    end
    
    methods (Static)
        function value = getLocalBranchNames(repo)
            %
            %
            %   value = git.base.branch_iterator.getLocalBranchNames(repo)
            
            iter = git.base.branch_iterator(repo,0);
            
            value = cell(20,1);
            I = 0;
            done = false;
            while ~done
                ref = iter.getNextBranch;
                if isempty(ref)
                    done = true;
                else
                    I = I + 1;
                    value{I} = ref.name;
                end
            end
            value(I+1:end) = [];
        end
        function value = getRemoteBranchNames()
            value = [];
        end
    end
    
    methods
        function obj = branch_iterator(repo,type)
            %
            %   obj = git.base.branch_iterator(repo,type)
            %
            %   Inputs
            %   ------
            %   type
            %       - 0, local
            %       - 1, remote
            %       - 2, all (default)
            
            obj.h = libgit(10,6,repo.h,type);
        end
        function [ref,out_type] = getNextBranch(obj)
            %
            %   Outputs
            %   -------
            %   ref : git.base.reference
            %       This is [] when no branches are left
            %   out_type :
            %       0 - local
            %       1 - remote
            
            [h,out_type] = libgit(10,10,obj.h); %#ok<PROP>
            if isempty(h) %#ok<PROP>
                ref = [];
            else
                ref = git.base.reference(h); %#ok<PROP>
            end
        end
        function delete(obj)
            libgit(10,5,obj.h);
        end
    end
    
end

