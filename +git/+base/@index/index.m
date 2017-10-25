classdef index
    %
    %   Class:
    %   git.base.index
    
    properties (Hidden)
        h
    end
    
    properties (Dependent)
        entry_count
    end
    
    methods
        function value = get.entry_count(obj)
            value = libgit(25,17,obj.h);
        end
    end
    
    methods
        function obj = index()
            obj.h = libgit(25,24);
        end
        function delete(obj)
            libgit(25,20,obj.h);
        end
    end
    
end

