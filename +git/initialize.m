function initialize()
%
%   git.initialize
%

p_root = fileparts(fileparts(which('git.initialize')));

addpath(fullfile(p_root,'c_code'));

end