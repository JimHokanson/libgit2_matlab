classdef status_entry
    %
    %   Class:
    %   git.base.status_entry
    %
    %   See Also
    %   --------
    %   git.base.diff_delta
    %   git.base.status_flag
    %   git.base.status_list
    %
    %   Returned By:
    %   git.base.status_list.getEntry()
    
    
%     typedef struct {
% 	git_status_t status;
% 	git_diff_delta *head_to_index;
% 	git_diff_delta *index_to_workdir;
% } git_status_entry;
    
    properties
        status %See git.base.status_flag
    end
    
    properties (Dependent)
        status_string
    end
    
    %TODO: These could be lazy ...
    %hold onto raw ...
    properties
        head_to_index
        index_to_workdir
    end
    
    methods
        function value = get.status_string(obj)
            value = git.base.status_flag.toString(obj.status);
        end
    end
    
    methods
        function obj = status_entry(s)
            %
            %   obj = git.base.status_entry(s)
            
            obj.status = s.status;
            if ~isempty(s.head_to_index)
                obj.head_to_index = git.base.diff_delta(s.head_to_index);
            end
            if ~isempty(s.index_to_workdir)
                obj.index_to_workdir = git.base.diff_delta(s.index_to_workdir);
            end
        end
    end
    
end

