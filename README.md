
# Standalone Deployed Game Server Monitored Using Instana
The goal of this project was to demonstrate usage of Instana to monitor irregular traffic on a game server being associated with cheating. However due to time constrain, I have abandoned it after deploying the Instana agent into my local Kubernetes cluster.

The steps are based on the tutorial series by trashart
https://www.youtube.com/watch?v=vWfWjbOIqMo

![](https://github.com/perrauo/devops-showcase-ue4/blob/main/server.gif)

![](/instana.png)


## 1. Ubuntu
The first step is to enable Windows Subsystem allowing us to use Ubuntu on windows.
### Enable Windows Subsystem for Linux

https://learn.microsoft.com/en-us/windows/wsl/install-manual
```
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```
```
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```
```
wsl --set-default-version 2
```
## 2. UE4 CLI
*  https://docs.adamrehn.com/ue4-docker/configuration/configuring-linux

```
sudo apt-get install python3 python3-dev python3-pip
```
```
sudo pip3 install ue4-docker
```
```
sudo ue4-docker setup
```

## 3. Build Unreal image myself due to licensing image
* Specify target full otherwise you will run out of space
* Specify custom branch because relying on tag will fail to run the configure step
```
ue4-docker build --target full --ue-version custom -repo https://github.com/EpicGames/UnrealEngine.git -branch 4.27
```

## 4. Build docker image for my server
```
cd /mnt/c/repos/DevopsShowcase/Game/Unreal
docker build -f Dockerfile.server -t devops-showcase-server .
docker run -t devops-showcase-server
```


## 5. Terraform
* https://developer.hashicorp.com/terraform/tutorials/aws-get-started/install-cli
```
sudo apt-get update && sudo apt-get install -y gnupg software-properties-common
```
```
wget -O- https://apt.releases.hashicorp.com/gpg | \
gpg --dearmor | \
sudo tee /usr/share/keyrings/hashicorp-archive-keyring.gpg > /dev/null
```
```
gpg --no-default-keyring \
--keyring /usr/share/keyrings/hashicorp-archive-keyring.gpg \
--fingerprint
```
```
echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] \
https://apt.releases.hashicorp.com $(lsb_release -cs) main" | \
sudo tee /etc/apt/sources.list.d/hashicorp.list
```
```
sudo apt update
```
```
sudo apt-get install terraform
```

## 6. Setup Kubernetes in Docker
* Set the `KUBECONFIG` environment variable to `%USERPROFILE%\.kube\config` on Windows
* Create a symbolic link between ubuntu .kube\config into windows kube config for WSL
```
sudo ln -sf "/mnt/c/users/$windowsUser/.kube" "/home/$linuxUser/.kube"
```

## 7. Enable Kubernetes in Docker


## 8. Initialize Terraform
* Cd into folder containing the terraform file
```
terraform init
terraform plan
terraform apply
```

## 9. Visualize Infrastructure using kubernetes ctl
```
kubectl get services
kubectl get deployments
kubectl get pods
```

## 10. Install Instana agent
* You should have received this information by email when starting your instana trial
* Navigate to your personalized link and choose Agent deployment > Kubernetes - Operator
* Namespace name usually default if not specified in your terraform file
```
helm install instana-agent \
--generate-name --namespace default \
--set agent.key=INSTANA_AGENT_KEY \
--set agent.endpointHost=HOST \
--set agent.endpointPort=PORT \
--set zone.name=CLUSTER_NAME \
--repo https://agents.instana.io/helm
```


