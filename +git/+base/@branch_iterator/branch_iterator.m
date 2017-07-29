classdef branch_iterator
    %
    %   Class:
    %   git.base.branch_iterator
    
    properties
        h
    end
    

    methods
        function obj = branch_iterator(repo,varargin)
            %
            %   Inputs
            %   ------
            %   type
            %   - 0
            %   - 1
            %   - 2
            
            
                % case 0:
                % list_flags = GIT_BRANCH_LOCAL;
                % break;
                % case 1:
                % list_flags = GIT_BRANCH_REMOTE;
                % break;
                % case 2:
                % list_flags = GIT_BRANCH_ALL;
            
            in.type = 0;
            in = sl.in.processVarargin(in,varargin);
            
            obj.h = libgit(10,6,repo.h,in.type);
            
        end
        function delete(obj)
            libgit(10,5,obj.h);
        end
    end
    
end

