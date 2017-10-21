classdef revwalk
    %
    %   Class:
    %   git.base.revwalk
    %
    %   See Also
    %   --------
    %   git.base.repository
    
    properties
        h
    end
    
    methods (Static)
        function walk = fromRepo(repo)
            h = libgit(52,7,repo.h);
            walk = git.base.revwalk(h);
        end
    end
    
    methods
        function obj = revwalk(h)
            %   
            %   obj = git.base.revwalk(h)
            
            obj.h = h;
        end
        function next(obj)
            %
            %
            %   next(obj)
            
            commit_oid_raw = libgit(52,8,obj.h);
            %temp is of type
        end
        function pushID(obj,commit_oid)
            %x Add a new root for the traversal
            %
            %   pushID(obj,commit_oid)
            %
            %   Do we want to log this?
            
            libgit(52,9,obj.h,commit_oid)
        end
        function pushHead(obj)
            %x Push the repository's HEAD
            %
            %   pushHead(obj)
            
            libgit(52,11,obj.h)
        end
        function pushGlob(obj,glob_string)
            %
            %
            %   pushGlob(obj,glob_string)
            
            libgit(52,10,obj.h,glob_string)
        end
    end
    
end

