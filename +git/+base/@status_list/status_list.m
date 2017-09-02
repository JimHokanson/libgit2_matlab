classdef status_list < handle
    %
    %   Class:
    %   git.base.status_list
    %   
    %   See Also
    %   --------
    %   git.base.status_entry
    
    %{
    Usage Notes
    -----------
    1) Files that have not been added will not show up in the list.
    
    
    
    %}
    
    properties
        h = 0%pointer
    end
    
    properties (Dependent)
        count
    end
    
    methods
        function value = get.count(obj)
            value = libgit(56,6,obj.h);
        end
    end
    
    methods (Static)
        function obj = fromRepo(repo,options)
            %
            %
            %   obj = git.base.status_list.fromRepo(repo,*options);
            %
            %   Inputs
            %   ------
            %   options : git.base.status_options
            
            
            
            if nargin == 1
                h = libgit(56,9,repo.h);
                obj = git.base.status_list(h);
            else
                %options
                %
                %   TODO: How to convert
                %
                %   h = mex(56,9,repo);
            end
        end
    end
    
    methods
        function obj = status_list(h)
            if ~isa(h,'int64')
                error('Invalid usage')
            end
            obj.h = h;
        end
        function entry = getEntry(obj,index_1b)
            %TODO: cast to git.base.status_entry
            entry = libgit(56,1,obj.h,index_1b-1);
        end
        function delete(obj)
            if obj.h ~= 0
                libgit(56,7,obj.h);
            end
        end
    end
    
end

