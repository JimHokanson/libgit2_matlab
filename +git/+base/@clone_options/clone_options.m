classdef clone_options
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
    end
    
end

% unsigned int	version
%
% git_checkout_options	checkout_opts These options are passed to the
% checkout step. To disable checkout, set the `checkout_strategy` to
% `GIT_CHECKOUT_NONE`.
% 
%git_fetch_options	fetch_opts
% Options which control the fetch, including callbacks. The callbacks are
% used for reporting fetch progress, and for acquiring credentials in the
% event they are needed.
% 
%int	bare
% Set to zero (false) to create a standard repo, or non-zero for a bare
% repo
% 
%git_clone_local_t	local
% Whether to use a fetch or copy the object database.
% 
%const char *	checkout_branch
% The name of the branch to checkout. NULL means use the remote's default
% branch.
% 
%git_repository_create_cb	repository_cb
% A callback used to create the new repository into which to clone. If
% NULL, the 'bare' field will be used to determine whether to create a bare
% repository.
% 
%void *	repository_cb_payload
% An opaque payload to pass to the git_repository creation callback. This
% parameter is ignored unless repository_cb is non-NULL.
% 
%git_remote_create_cb	remote_cb
% A callback used to create the git_remote, prior to its being used to
% perform the clone operation. See the documentation for
% git_remote_create_cb for details. This parameter may be NULL, indicating
% that git_clone should provide default behavior.
% 
%void *	remote_cb_payload
% An opaque payload to pass to the git_remote creation callback. This
% parameter is ignored unless remote_cb is non-NULL.
% 
