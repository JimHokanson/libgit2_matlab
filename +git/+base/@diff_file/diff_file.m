classdef diff_file
    %
    %   Class:
    %   git.base.diff_file
    %
    %   TODO: Flush this out more ...
    
    
%     typedef struct {
% 	git_oid     id;
% 	const char *path;
% 	git_off_t   size;
% 	uint32_t    flags;
% 	uint16_t    mode;
% 	uint16_t    id_abbrev;
% } git_diff_file;
    
    properties
        id   %git.base.oid
        path
        size
        flags
        mode
        id_abbrev
    end
    
    methods
        function obj = diff_file(s)
            %
            %   obj = git.base.diff_file(s)
            
            obj.id = git.base.oid(s.id);
            obj.path = s.path;
            obj.size = s.size;
            obj.flags = s.flags;
            obj.mode = s.mode;
            obj.id_abbrev = s.id_abbrev;
            
        end
    end
    
end

