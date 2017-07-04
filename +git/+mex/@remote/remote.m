classdef remote
    %
    %   Class:
    %   git.mex.remote
    %
    %   See Also
    %   --------
    %   git.base.remote
    
    %TODO: Move all api calls into here ...
    
    properties
    end
    
    methods (Static)
        function remote = lookup_remote(repo,remote_name)
            %TODO: Do input checking
            
            
            remote = libgit(1,22,repo,remote_name);
        end
    end
    
end

