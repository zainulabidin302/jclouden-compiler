set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set number
set colorcolumn=110

nnoremap <F4> :make!<cr>
nnoremap <F5> :!./a.out<cr>
nnoremap <F6> :make! <bar> ./a.out<cr>
nnoremap <F7> :w! \| :make! <bar> !./a.out sample_file<cr>

