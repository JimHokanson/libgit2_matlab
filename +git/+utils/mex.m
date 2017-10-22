function mex()
%
%   git.utils.mex
%
%   When written calling this command will compile/recompile the relevant
%   mex files for this code.

[~,mex_names] = inmem;

%This isn't allowing us to get rid of libgit.mexw64, why????
if any(strcmp(mex_names,'libgit'))
    munlock('libgit');
    clear('libgit');
end

%TODO: Provide the compiling code ...

end