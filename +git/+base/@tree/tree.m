classdef tree
    %
    %   Class:
    %   git.base.tree
    
    properties
        h
    end
    
    methods (Static)
        function obj = fromID(id)
            %TODO
        end
    end
    
    methods
        function obj = tree(tree_h)
            %
            %   obj = git.base.tree(tree_h);
            
            obj.h = tree_h;
        end
    end
    
end

