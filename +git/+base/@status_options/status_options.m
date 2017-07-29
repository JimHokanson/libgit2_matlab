classdef status_options < handle
    %
    %   Class:
    %   git.base.status_options
        
    properties
        version %numeric
        show %git.base.status_options.status_show

        flags %git.base.status_options.flags
        pathspec %cellstr
    end
    
    methods
        function obj = status_options()
            %
            %   s = git.base.status_options
            
            %Initialization
            s = libgit(56,5);
            obj.version = s.version;
            obj.show = s.show;
            obj.flags = s.flags;
            obj.pathspec = s.pathspec;
        end
    end
    
end

