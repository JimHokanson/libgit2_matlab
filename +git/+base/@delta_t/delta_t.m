classdef delta_t
    %
    %   Class:
    %   git.base.delta_t
    
    properties (Constant)
        UNMODIFIED = 0
        ADDED = 1
        DELETED = 2
        MODIFIED = 3
        RENAMED = 4
        COPIED = 5
        IGNORED = 6
        UNTRACKED = 7
        TYPECHANGE = 8
        UNREADABLE = 9
        CONFLICTED = 10
    end
    
    methods (Static)
        function str = toString(value)
            str = git.utils.enumToString('git.base.status_options.flags',value);
        end
    end
    
end

% typedef enum {
% 	GIT_DELTA_UNMODIFIED = 0,  /**< no changes */
% 	GIT_DELTA_ADDED = 1,	   /**< entry does not exist in old version */
% 	GIT_DELTA_DELETED = 2,	   /**< entry does not exist in new version */
% 	GIT_DELTA_MODIFIED = 3,    /**< entry content changed between old and new */
% 	GIT_DELTA_RENAMED = 4,     /**< entry was renamed between old and new */
% 	GIT_DELTA_COPIED = 5,      /**< entry was copied from another old entry */
% 	GIT_DELTA_IGNORED = 6,     /**< entry is ignored item in workdir */
% 	GIT_DELTA_UNTRACKED = 7,   /**< entry is untracked item in workdir */
% 	GIT_DELTA_TYPECHANGE = 8,  /**< type of entry changed between old and new */
% 	GIT_DELTA_UNREADABLE = 9,  /**< entry is unreadable */
% 	GIT_DELTA_CONFLICTED = 10, /**< entry in the index is conflicted */
% } git_delta_t;