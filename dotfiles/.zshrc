PROMPT="%{$fg[red]%}%n%{$reset_color%}@%{$fg[blue]%}%m %{$fg_no_bold[yellow]%}%1~ %{$reset_color%}%# "
RPROMPT="[%{$fg_no_bold[yellow]%}%?%{$reset_color%}]"

autoload -Uz compinit
compinit

#alias do 'ls'
alias ls='ls --color=auto'

#desatvar beep chato no console 
#sem output
setterm -blength 0 &> /dev/null
setterm -bfreq 0 &> /dev/null

#desativar beep chato no Xserver
#also sem output
xset b 0 &> /dev/null
xset b off &> /dev/null

#teclas home e end para mudar cursor de posição
bindkey "${terminfo[khome]}" beginning-of-line
bindkey "${terminfo[kend]}" end-of-line

#dirstack config
DIRSTACKFILE="$HOME/.cache/zsh/dirs"
if [[ -f $DIRSTACKFILE ]] && [[ $#dirstack -eq 0 ]]; then
  dirstack=( ${(f)"$(< $DIRSTACKFILE)"} )
  [[ -d $dirstack[1] ]] && cd $dirstack[1]
fi
chpwd() {
  print -l $PWD ${(u)dirstack} >$DIRSTACKFILE
}

DIRSTACKSIZE=20

setopt AUTO_PUSHD PUSHD_SILENT PUSHD_TO_HOME

## Remove duplicate entries
setopt PUSHD_IGNORE_DUPS

## This reverts the +/- operators.
setopt PUSHD_MINUS

#export environment variables to intellij
export PATH=$PATH:/usr/lib/jvm/java-8-jdk/bin/
export JAVA_HOME=/usr/lib/jvm/java-8-jdk/

