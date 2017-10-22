classdef features < handle
    %
    %   Class:
    %   git.base.libgit.features
    %
    %   See Also
    %   --------
    %   git.base.libgit.version
    
    properties
        threads
        https
        ssh
    end
    
    methods
        function obj = features()
            %
            %   f = git.base.libgit.features
            
            temp = libgit(4,0);
            obj.threads = temp(1);
            obj.https = temp(2);
            obj.ssh = temp(3);
        end
    end
    
end

