classdef remote_callbacks
    %
    %   Class:
    %   git.base.remote_callbacks
    
    properties
        version
        
        sideband_progress
        %         /**
        % 	 * Textual progress from the remote. Text send over the
        % 	 * progress side-band will be passed to this function (this is
        % 	 * the 'counting objects' output).
        % 	 */
        
        completion %Currently Unused
        %         	/**
        % 	 * Completion is called when different parts of the download
        % 	 * process are done (currently unused).
        % 	 */
        
        credentials  %git_cred_acquire_cb
        %This will be called if the remote host requires authentication in
        %order to connect to it. Returning GIT_PASSTHROUGH will make
        %libgit2 behave as though this field isn't set.
        
        certificate_check  %git_transport_certificate_check_cb
        %         	/**
        % 	 * If cert verification fails, this will be called to let the
        % 	 * user make the final decision of whether to allow the
        % 	 * connection to proceed. Returns 1 to allow the connection, 0
        % 	 * to disallow it or a negative value to indicate an error.
        % 	 */
        
        transfer_progress  %git_transfer_progress_cb
        %         	/**
        % 	 * During the download of new data, this will be regularly
        % 	 * called with the current count of progress done by the
        % 	 * indexer.
        % 	 */

        update_tips   %int (*update_tips)(const char *refname, const git_oid *a, const git_oid *b, void *data);
        %         	/**
        % 	 * Each time a reference is updated locally, this function
        % 	 * will be called with information about it.
        % 	 */
        
        pack_progress  %git_packbuilder_progress
        %         	/**
        % 	 * Function to call with progress information during pack
        % 	 * building. Be aware that this is called inline with pack
        % 	 * building operations, so performance may be affected.
        % 	 */
        
        push_transfer_progress  %git_push_transfer_progress
        %         	/**
        % 	 * Function to call with progress information during the
        % 	 * upload portion of a push. Be aware that this is called
        % 	 * inline with pack building operations, so performance may be
        % 	 * affected.
        % 	 */
        
        push_update_reference
        %         	/**
        % 	 * Called for each updated reference on push. If `status` is
        % 	 * not `NULL`, the update was rejected by the remote server
        % 	 * and `status` contains the reason given.
        % 	 */
        
        push_negotiation  %git_push_negotiation
        %         	/**
        % 	 * Called once between the negotiation step and the upload. It
        % 	 * provides information about what updates will be performed.
        % 	 */
        
        transport %git_transport_cb
        %         /**
        %      * Create the transport to use for this operation. Leave NULL
        %      * to auto-detect.
        %      */
        
        payload
        %         	/**
        % 	 * This will be passed to each of the callbacks in this struct
        % 	 * as the last parameter.
        % 	 */
        
    end
    
    methods
        function obj = remote_callbacks()
            
            %Callback process
            %
            %   User sets either:
            %   1) A callback function
            %   2) Credentials
            
            %If credentials, we supply a mex default function
            %That passes the credentials, do we need to switch on type?
            %   => I don't think so 
        end
        function struct(obj)
            %
            %   Write code that converts to struct
            
        end
    end
    
end

