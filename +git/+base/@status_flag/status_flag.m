classdef status_flag
    %
    %   Class:
    %   git.base.status_flag
    
%         typedef enum {
%         GIT_STATUS_CURRENT = 0,
% 
%         GIT_STATUS_INDEX_NEW        = (1u << 0),
%         GIT_STATUS_INDEX_MODIFIED   = (1u << 1),
%         GIT_STATUS_INDEX_DELETED    = (1u << 2),
%         GIT_STATUS_INDEX_RENAMED    = (1u << 3),
%         GIT_STATUS_INDEX_TYPECHANGE = (1u << 4),
% 
%         GIT_STATUS_WT_NEW           = (1u << 7),
%         GIT_STATUS_WT_MODIFIED      = (1u << 8),
%         GIT_STATUS_WT_DELETED       = (1u << 9),
%         GIT_STATUS_WT_TYPECHANGE    = (1u << 10),
%         GIT_STATUS_WT_RENAMED       = (1u << 11),
%         GIT_STATUS_WT_UNREADABLE    = (1u << 12),
% 
%         GIT_STATUS_IGNORED          = (1u << 14),
%         GIT_STATUS_CONFLICTED       = (1u << 15),
%     } git_status_t;

    properties
        CURRENT = 0
        
        INDEX_NEW = 2^0
        INDEX_MODIFIED = 2^1
        INDEX_DELETED = 2^2
        INDEX_RENAMED = 2^3
        INDEX_TYPECHANGE = 2^4
        
        WT_NEW = 2^7
        WT_MODIFIED = 2^8
        WT_DELETED = 2^9
        WT_TYPECHANGE = 2^10
        WT_RENAMED = 2^11
        WT_UNREADABLE = 2^12
        
        IGNORED = 2^14
        CONFLICTED = 2^15
    end
    
    methods (Static)
        function str = toString(value)
            str = git.utils.enumToString('git.base.status_flag',value);
        end
    end
    
end

