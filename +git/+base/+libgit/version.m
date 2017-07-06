classdef version
    %
    %   Class:
    %   git.base.libgit.version
    
    properties
        major
        minor
        rev
    end
    
    methods
        function obj = version()
            %
            %   v = git.base.libgit.version
            
            temp = libgit(4,3);
            obj.major = temp(1);
            obj.minor = temp(2);
            obj.rev = temp(3); 
        end
    end
    
end

