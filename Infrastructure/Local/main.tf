provider "kubernetes" {
  config_path = "~/.kube/config"
}

resource "kubernetes_service" "devops_showcase" {
  metadata {
    name = "devops-showcase-server"
    labels = {
      game = "devops_showcase"
    }
  }
  spec {
    selector = {
      game = kubernetes_deployment.devops_showcase.metadata.0.labels.game
    }
    port {
      port        = 7777
      protocol    = "UDP"
    }

    type = "LoadBalancer"
  }
}

resource "kubernetes_deployment" "devops_showcase" {
  metadata {
    name = "devops-showcase-server"
    labels = {
      game = "devops_showcase"
    }
  }

  spec {
    replicas = 1

    selector {
      match_labels = {
        game = "devops_showcase"
      }
    }

    template {
      metadata {
        labels = {
          game = "devops_showcase"
        }
      }

      spec {
        container {
          image = "devops-showcase-server:latest"
          image_pull_policy = "IfNotPresent"
          name  = "devops-showcase-server"
          port {
            container_port = 7777
            protocol = "UDP"
          }
        }
      }
    }
  }
}