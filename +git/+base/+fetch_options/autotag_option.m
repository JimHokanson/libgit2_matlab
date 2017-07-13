classdef autotag_option
    %
    %   Class:
    %   git.base.fetch_options.autotag_option
    
    %TODO: Move documentaton of options up here
    properties
        UNSPECIFIED = 0
        AUTO = 1
        NONE = 2
        ALL = 3       
    end
    
end

%{

classdef WeekDays
   enumeration
      Monday, Tuesday, Wednesday, Thursday, Friday
   end
%}

%{
typedef enum {
	/**
	 * Use the setting from the configuration.
	 */
	GIT_REMOTE_DOWNLOAD_TAGS_UNSPECIFIED = 0,
	/**
	 * Ask the server for tags pointing to objects we're already
	 * downloading.
	 */
	GIT_REMOTE_DOWNLOAD_TAGS_AUTO,
	/**
	 * Don't ask for any tags beyond the refspecs.
	 */
	GIT_REMOTE_DOWNLOAD_TAGS_NONE,
	/**
	 * Ask for the all the tags.
	 */
	GIT_REMOTE_DOWNLOAD_TAGS_ALL,
} git_remote_autotag_option_t;

%}