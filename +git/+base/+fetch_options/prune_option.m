classdef prune_option
    %
    %   Class:
    %   git.base.fetch_options.prune_option
    
    properties
        UNSPECIFIED = 0
        PRUNE = 1
        NO_PRUNE = 2
    end
    
    methods
    end
    
end

%{
typedef enum {
	/**
	 * Use the setting from the configuration
	 */
	GIT_FETCH_PRUNE_UNSPECIFIED,
	/**
	 * Force pruning on
	 */
	GIT_FETCH_PRUNE,
	/**
	 * Force pruning off
	 */
	GIT_FETCH_NO_PRUNE,
} git_fetch_prune_t;


%}