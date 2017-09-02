classdef diff_delta
    %
    %   Class:
    %   git.base.diff_delta
    
%     typedef struct {
% 	git_delta_t   status;
% 	uint32_t      flags;	   /**< git_diff_flag_t values */
% 	uint16_t      similarity;  /**< for RENAMED and COPIED, value 0-100 */
% 	uint16_t      nfiles;	   /**< number of files in this delta */
% 	git_diff_file old_file;
% 	git_diff_file new_file;
% } git_diff_delta;
    
    properties
        status %git.base.delta_t
    end
    
    properties (Dependent)
        status_string 
    end
    
    methods
        function value = get.status_string(obj)
            value = git.base.delta_t.toString(obj.status);
        end
    end
    
    properties
        
        
        flags       
% typedef enum {
% 	GIT_DIFF_FLAG_BINARY     = (1u << 0), /**< file(s) treated as binary data */
% 	GIT_DIFF_FLAG_NOT_BINARY = (1u << 1), /**< file(s) treated as text data */
% 	GIT_DIFF_FLAG_VALID_ID   = (1u << 2), /**< `id` value is known correct */
% 	GIT_DIFF_FLAG_EXISTS     = (1u << 3), /**< file exists at this side of the delta */
% } git_diff_flag_t;
        
        similarity        
    %  * The similarity score is zero unless you call `git_diff_find_similar()`
    %  * which does a similarity analysis of files in the diff.  Use that
    %  * function to do rename and copy detection, and to split heavily modified
    %  * files in add/delete pairs.  After that call, deltas with a status of
    %  * GIT_DELTA_RENAMED or GIT_DELTA_COPIED will have a similarity score
    %  * between 0 and 100 indicating how similar the old and new sides are.
        
        n_files
        old_file
        new_file
    end
    
    methods
        function obj = diff_delta(s)
            %
            %   obj = git.base.diff_delta(s)
                        
            obj.status = s.status;
            
            obj.flags = s.flags;
            %TODO: Break out the flags ...
            %
            %is_binary
            %valid_id
            %exists
            
            obj.similarity = s.similarity;
            obj.n_files = s.nfiles;
            obj.old_file = git.base.diff_file(s.old_file);
            obj.new_file = git.base.diff_file(s.new_file);
            
        end
    end
    
end

