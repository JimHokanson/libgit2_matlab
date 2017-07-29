classdef flags < handle
    %
    %   Class:
    %   git.base.status_options.flags
    
    
%   GIT_STATUS_OPT_INCLUDE_UNTRACKED                = (1u << 0),
% 	GIT_STATUS_OPT_INCLUDE_IGNORED                  = (1u << 1),
% 	GIT_STATUS_OPT_INCLUDE_UNMODIFIED               = (1u << 2),
% 	GIT_STATUS_OPT_EXCLUDE_SUBMODULES               = (1u << 3),
% 	GIT_STATUS_OPT_RECURSE_UNTRACKED_DIRS           = (1u << 4),
% 	GIT_STATUS_OPT_DISABLE_PATHSPEC_MATCH           = (1u << 5),
% 	GIT_STATUS_OPT_RECURSE_IGNORED_DIRS             = (1u << 6),
% 	GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX            = (1u << 7),
% 	GIT_STATUS_OPT_RENAMES_INDEX_TO_WORKDIR         = (1u << 8),
% 	GIT_STATUS_OPT_SORT_CASE_SENSITIVELY            = (1u << 9),
% 	GIT_STATUS_OPT_SORT_CASE_INSENSITIVELY          = (1u << 10),
% 	GIT_STATUS_OPT_RENAMES_FROM_REWRITES            = (1u << 11),
% 	GIT_STATUS_OPT_NO_REFRESH                       = (1u << 12),
% 	GIT_STATUS_OPT_UPDATE_INDEX                     = (1u << 13),
% 	GIT_STATUS_OPT_INCLUDE_UNREADABLE               = (1u << 14),
% 	GIT_STATUS_OPT_INCLUDE_UNREADABLE_AS_UNTRACKED  = (1u << 15),
    
    properties
        INCLUDE_UNTRACKED = 2^0
        INCLUDE_IGNORED = 2^1
        INCLUDE_UNMODIFIED = 2^2
        EXCLUDE_SUBMODULES = 2^3
        RECURSE_UNTRACKED_DIRS = 2^4
        DISABLE_PATHSPEC_MATCH = 2^5
        RECURSE_IGNORED_DIRS = 2^6
        RENAMES_HEAD_TO_INDEX = 2^7
        RENAMES_INDEX_TO_WORKDIR = 2^8
        SORT_CASE_SENSITIVELY = 2^9
        SORT_CASE_INSENSITIVELY = 2^10
        RENAMES_FROM_REWRITES = 2^11
        NO_REFRESH = 2^12
        UPDATE_INDEX = 2^13
        INCLUDE_UNREADABLE = 2^14
        INCLUDE_UNREADABLE_AS_UNTRACKED = 2^15
    end
    
    methods (Static)
        function str = toString(value)
            str = '';
            %TODO: Use meta to get propertis and convert bits
            %to property strings
        end
    end
    
end

