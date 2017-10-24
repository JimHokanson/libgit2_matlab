classdef config_iterator
    %
    %   Class:
    %   git.base.config_iterator
    
    properties (Hidden)
        h
    end
    
    methods
        function obj = config_iterator(h)
            %   
            %   obj = git.base.config_iterator(h)
            
            obj.h = h;
        end
        function delete(obj)
            libgit(15,24,obj.h)
        end
    end
    
end

