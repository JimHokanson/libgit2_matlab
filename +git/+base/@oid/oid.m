classdef oid
    %
    %   Class:
    %   git.base.oid
    %
    %   See Also
    %   --------
    
    properties (Hidden)
        h
    end
    
    properties (Dependent)
        raw
        hex
    end
    
    methods
    end
    
end

%git_oid_cmp
%git_oid_cpy
%git_oid_equal
%git_oid_fmt - Format a git_oid into a hex string.
%git_oid_fromraw - Copy an already raw oid into a git_oid structure.
%git_oid_fromstr - Parse a hex formatted object id into a git_oid.
%git_oid_fromstrn - Parse N characters of a hex formatted object id into a git_oid.
%git_oid_fromstrp - Parse a hex formatted null-terminated string into a git_oid.
%git_oid_iszero - Check is an oid is all zeros.
%git_oid_ncmp
%git_oid_nfmt
%git_oid_pathfmt - Format a git_oid into a loose-object path string.

%GIT shortener
%-------------------
%git_oid_shorten_add
%git_oid_shorten_free
%git_oid_shorten_new

%git_oid_strcmp
%git_oid_streq
%git_oid_tostr - Format a git_oid into a buffer as a hex format c-string.
%git_oid_tostr_s - Format a git_oid into a statically allocated c-string.