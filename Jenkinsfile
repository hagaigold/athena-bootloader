pipeline {
    agent any
    stages {
        stage('build1') {
            steps {
                sh './hello'
            }
        }
        stage('build2') {
            steps {
            script {
                try {
                    sh './test.sh'
                }
                catch (err) {
                    echo "Failed: ${err}"
                }
                finally {
                    echo 'go own...'
                }
            }}
        }
        stage('build3') {
            steps {
                sh './hello'
            }
        }

    }
    post {
        always {
            echo 'This will always run'
        }
        success {
            echo 'This will run only if successful'
        }
        failure {
            echo 'This will run only if failed'
        }
        unstable {
            echo 'This will run only if the run was marked as unstable'
        }
        changed {
            echo 'This will run only if the state of the Pipeline has changed'
        }
    }
}
