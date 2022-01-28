pipeline {
    agent any
    stages {
        stage('build1') {
            steps {
                bat 'hello'
            }
        }
        stage('build2') {
            steps {
            script {
                try {
                    bat 'sh test.sh'
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
                bat 'hello'
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
            echo 'For example, if the Pipeline was previously failing but is now successful'
        }
    }
}
