classdef config
    %
    %   Class:
    %   git.base.config
    
    properties (Hidden)
        h
    end
    
    methods
        function obj = config(h)
            obj.h = h;
        end
        function iter = getIterator(obj)
            iter_h = libgit(15,26,obj.h);
            iter = git.base.config_iterator(iter_h);
        end
        function delete(obj)
            libgit(15,13,obj.h);
        end
    end
    
end

