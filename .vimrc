set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set number
set colorcolumn=110
highlight ColorColumn ctermbg=darkgray

augroup project
	autocmd!
	autocmd BufRead,BufNewFile *.h,*.c set filetype=c.doxygen
augroup END

let &path.="src/include,"

nnoremap <F4> :make!<cr>
nnoremap <F5> :!./a.out<cr>
nnoremap <F6> :make! <bar> ./a.out<cr>
nnoremap <F7> :w! \| :make! <bar> !./a.out sample_file<cr>

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
