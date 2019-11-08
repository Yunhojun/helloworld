using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraScript : MonoBehaviour
{
    [SerializeField]
    float speed = 1f;

    // Start is called before the first frame update
    void Start()
    {
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        float h = Input.GetAxisRaw("Horizontal");
        float v = Input.GetAxisRaw("Vertical");
        move(h, v);

        float rx = Input.GetAxis("Mouse X");
        float ry = Input.GetAxis("Mouse Y");
        transform.rotation = Quaternion.Euler(ry, rx, 0);
    }

    private void move(float h, float v)
    {
        Vector3 dir = new Vector3(h, 0, v);      
        transform.Translate(dir.normalized * speed * Time.deltaTime);
    }
}
