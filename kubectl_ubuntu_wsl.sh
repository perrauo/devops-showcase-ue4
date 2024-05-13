linuxUser=$1
windowsUser=$2

sudo mkdir -p /$linuxUser/.kube
sudo ln -sf "/mnt/c/users/$windowsUser/.kube" "/home/$linuxUser/.kube"
